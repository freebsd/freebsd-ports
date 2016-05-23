# Created by: Julian Stacey <jhs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hylafax
PORTVERSION=	6.0.6
PORTREVISION=	6
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fax software

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	${LOCALBASE}/lib/afm/Courier:print/afm
LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libjbig.so:graphics/jbigkit

MAKE_JOBS_UNSAFE=	yes
HAS_CONFIGURE=	yes
USES=		fakeroot ghostscript jpeg

CONFIGURE_ARGS=	--with-INSTALL="" \
		--with-LIBTIFF="-L${LOCALBASE}/lib -ltiff -ljpeg" \
		--with-ZLIB=no --with-LIBZ=-lz \
		--with-TIFFINC="-I${LOCALBASE}/include" \
		--with-GCOPTS=" " --with-GCXXOPTS=" " \
		--with-REGEX=no --with-LIBREGEX='' --with-REGEXINC=-I/usr/include \
		--with-DIR_HTML="${DOCSDIR}" \
		--with-GETTY=SysV
CFLAGS+=	-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED -Wall -L${LOCALBASE}/lib
CONFIGURE_ENV=	ENVOPTS="${CFLAGS}"
MAKE_ENV+=	ROOT=${STAGEDIR}
MAKE_ARGS+=	OPTIMIZER="" -DOPTIMIZER

PORTDOCS=	RELEASENOTES-4.3.txt RELEASENOTES-4.4.txt RELEASENOTES-6.0.txt
SUB_FILES=	pkg-message
USE_RC_SUBR=	hylafax

OPTIONS_DEFINE=	PAM NLS GAWK DOCS
OPTIONS_DEFAULT=PAM
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
GAWK_DESC=	Use gawk for scripts

PAM_CONFIGURE_OFF=	--disable-pam
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
GAWK_BUILD_DEPENDS=	gawk:lang/gawk
GAWK_RUN_DEPENDS=	gawk:lang/gawk
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

post-patch:
	${REINPLACE_CMD} \
		-e 's,/usr/local,${LOCALBASE},g' \
		-e 's,-ljbig,-L${LOCALBASE}/lib &,' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,-O hfaxd.conf,-O hfaxd.conf.sample,' \
		${WRKSRC}/hfaxd/Makefile.in
	${REINPLACE_CMD} -e 's,hosts.hfaxd,hosts.hfaxd.sample,' \
		${WRKSRC}/etc/Makefile.in
	${REINPLACE_CMD} -e 's,-O typerules,-O typerules.sample,' \
		-e 's,-O pagesizes,-O pagesizes.sample -src pagesizes,' \
		${WRKSRC}/libhylafax/Makefile.in

pre-install:
	${MKDIR} ${STAGEDIR}${HYLAFAX_SPOOL}/archive \
		${STAGEDIR}${HYLAFAX_SPOOL}/docq \
		${STAGEDIR}${HYLAFAX_SPOOL}/doneq \
		${STAGEDIR}${HYLAFAX_SPOOL}/pollq \
		${STAGEDIR}${HYLAFAX_SPOOL}/sendq \
		${STAGEDIR}${HYLAFAX_SPOOL}/tmp \
		${STAGEDIR}${HYLAFAX_SPOOL}/info \
		${STAGEDIR}${HYLAFAX_SPOOL}/log

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
