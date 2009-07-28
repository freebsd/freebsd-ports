# ports collection makefile for:	hylafax
# Date created:		16 May 1995
# Whom:			Julian Stacey <jhs@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	hylafax
PORTVERSION=	6.0.3
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/source/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Fax software

BUILD_DEPENDS=	${LOCALBASE}/lib/afm/Courier:${PORTSDIR}/print/afm
LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		jbig.1:${PORTSDIR}/graphics/jbigkit

USE_GHOSTSCRIPT=yes

CONFIGURE_ARGS=	--with-INSTALL="" \
		--with-LIBTIFF="-L${LOCALBASE}/lib -ltiff -ljpeg" \
		--with-ZLIB=no --with-LIBZ=-lz \
		--with-TIFFINC="-I${LOCALBASE}/include" \
		--with-GCOPTS=" " --with-GCXXOPTS=" " \
		--with-REGEX=no --with-LIBREGEX='' --with-REGEXINC=-I/usr/include \
		--with-DIR_HTML="${DOCSDIR}"
CFLAGS+=	-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED -Wall -L${LOCALBASE}/lib

PORTDOCS=	RELEASENOTES-4.3.txt RELEASENOTES-4.4.txt RELEASENOTES-6.0.txt
SUB_FILES=	pkg-message
USE_RC_SUBR=	hylafax.sh

# Defaults to "North American Letter".  Use "ISO A4" for A4.
.if defined(PAGESIZE)
CONFIGURE_ARGS+=--with-PAGESIZE="${PAGESIZE}"
.endif

# Want PAM?
.if defined(WITHOUT_PAM)
CONFIGURE_ARGS+=--disable-pam
.endif

# Want HTML documentation?
.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=--with-HTML=yes
PLIST_SUB+=	PORTDOCS=""
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

.if defined(PACKAGE_BUILDING) || defined(BATCH)
CONFIGURE_ARGS+=--nointeractive
.endif

.if defined(WITH_GAWK)
BUILD_DEPENDS+=	gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS+=	gawk:${PORTSDIR}/lang/gawk
CONFIGURE_ARGS+=--with-AWK="${LOCALBASE}/bin/gawk"
.endif

MAKE_ARGS+=	OPTIMIZER="" -EOPTIMIZER
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	ENVOPTS="${CFLAGS}"

MAN1=	edit-faxcover.1 faxalter.1 faxcover.1 faxmail.1 faxrm.1 faxstat.1 \
	hylafax-client.1 sendfax.1 sendpage.1 sgi2fax.1 textfmt.1

MAN5=	dialrules.5f doneq.5f hosts.hfaxd.5f \
	hylafax-config.5f hylafax-info.5f hylafax-log.5f hylafax-server.5f \
	hylafax-shutdown.5f pagermap.5f pagesizes.5f recvq.5f sendq.5f \
	status.5f tsi.5f typerules.5f xferfaxlog.5f

MAN8=	choptest.8c cqtest.8c dialtest.8c faxabort.8c faxaddmodem.8c \
	faxadduser.8c faxanswer.8c faxconfig.8c faxcron.8c faxdeluser.8c \
	faxgetty.8c faxinfo.8c faxlock.8c faxmodem.8c faxq.8c \
	faxqclean.8c faxquit.8c faxrcvd.8c faxsend.8c faxsetup.8c faxstate.8c \
	faxwatch.8c hfaxd.8c jobcontrol.8c mkcover.8c notify.8c pagesend.8c pdf2fax.8c \
	pollrcvd.8c ps2fax.8c recvstats.8c tagtest.8c tiff2fax.8c \
	tiffcheck.8c tsitest.8c wedged.8c xferfaxstats.8c

SUID_EXES=	${PREFIX}/sbin/faxgetty ${PREFIX}/sbin/faxq \
		${PREFIX}/bin/faxrm ${PREFIX}/bin/faxalter

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	WITH_NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	WITH_NLS="@comment "
.endif

pre-extract:
	@if [ -d /var/db/pkg/tiff-3.6.1 ]; then \
		${ECHO_MSG} ""; \
		${ECHO_MSG} "Hylafax does not work with libtiff-3.6.1."; \
		${ECHO_MSG} "Please upgrade to libtiff-3.6.1_1. (/usr/ports/graphics/tiff)"; \
		${ECHO_MSG} ""; \
		exit 1; \
	fi

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

post-install:
	${CHOWN} uucp ${SUID_EXES}
	${CHMOD} 4555 ${SUID_EXES}
.for f in hfaxd.conf pagesizes typerules
	if [ ! -f ${PREFIX}/lib/fax/${f} ]; then ${CP} -p ${PREFIX}/lib/fax/${f}-dist ${PREFIX}/lib/fax/${f}; fi
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
