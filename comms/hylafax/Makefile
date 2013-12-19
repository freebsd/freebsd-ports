# Created by: Julian Stacey <jhs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hylafax
PORTVERSION=	6.0.6
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/source/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Fax software

BUILD_DEPENDS=	${LOCALBASE}/lib/afm/Courier:${PORTSDIR}/print/afm
LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libjbig.so:${PORTSDIR}/graphics/jbigkit

MAKE_JOBS_UNSAFE=	yes
#NO_STAGE=	yes
NEED_ROOT=	yes

USE_GHOSTSCRIPT=yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-INSTALL="" \
		--with-LIBTIFF="-L${LOCALBASE}/lib -ltiff -ljpeg" \
		--with-ZLIB=no --with-LIBZ=-lz \
		--with-TIFFINC="-I${LOCALBASE}/include" \
		--with-GCOPTS=" " --with-GCXXOPTS=" " \
		--with-REGEX=no --with-LIBREGEX='' --with-REGEXINC=-I/usr/include \
		--with-DIR_HTML="${DOCSDIR}"
CFLAGS+=	-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED -Wall -L${LOCALBASE}/lib
CONFIGURE_ENV=	ENVOPTS="${CFLAGS}"
MAKE_ENV+=	ROOT=${STAGEDIR}
MAKE_ARGS+=	OPTIMIZER="" -DOPTIMIZER

PORTDOCS=	RELEASENOTES-4.3.txt RELEASENOTES-4.4.txt RELEASENOTES-6.0.txt
SUB_FILES=	pkg-message
USE_RC_SUBR=	hylafax

SUID_EXES=	${STAGEDIR}${PREFIX}/sbin/faxgetty \
		${STAGEDIR}${PREFIX}/sbin/faxq \
		${STAGEDIR}${PREFIX}/bin/faxrm \
		${STAGEDIR}${PREFIX}/bin/faxalter

OPTIONS_DEFINE=	PAM NLS GAWK DOCS
OPTIONS_DEFAULT=PAM NLS
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
GAWK_DESC=	Use gawk for scripts

PAM_CONFIGURE_OFF=	--disable-pam
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
GAWK_BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk
GAWK_RUN_DEPENDS=	gawk:${PORTSDIR}/lang/gawk
GAWK_CONFIGURE_ON=	--with-AWK="${LOCALBASE}/bin/gawk"
DOCS_CONFIGURE_ON=	--with-HTML=yes

.include <bsd.port.options.mk>

# Defaults to "North American Letter".  Use "ISO A4" for A4.
.if defined(PAGESIZE)
CONFIGURE_ARGS+=--with-PAGESIZE="${PAGESIZE}"
.endif

# Redefine path for spool
.if defined(HYLAFAX_SPOOL)
CONFIGURE_ARGS+=--with-DIR_SPOOL="${HYLAFAX_SPOOL}"
.endif
HYLAFAX_SPOOL?=	/var/spool/hylafax
PLIST_SUB+=	HYLAFAX_SPOOL=${HYLAFAX_SPOOL}

.if defined(PACKAGE_BUILDING) || defined(BATCH)
CONFIGURE_ARGS+=--nointeractive
.endif

.if ${OSVERSION} >= 900007
CONFIGURE_ARGS+=	--with-GETTY=SysV
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's,/usr/local,${LOCALBASE},g' \
		-e 's,-ljbig,-L${LOCALBASE}/lib &,' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,-O hfaxd.conf,-O hfaxd.conf-dist,' \
		${WRKSRC}/hfaxd/Makefile.in
	${REINPLACE_CMD} -e 's,-O typerules,-O typerules-dist,' \
		-e 's,-O pagesizes,-O pagesizes-dist -src pagesizes,' \
		${WRKSRC}/libhylafax/Makefile.in

pre-install:
	${MKDIR} ${STAGEDIR}${HYLAFAX_SPOOL}

post-install:
	${CHOWN} uucp ${SUID_EXES}
	${CHMOD} 4555 ${SUID_EXES}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
