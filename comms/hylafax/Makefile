# ports collection makefile for:	hylafax
# Date created:		16 May 1995
# Whom:			Julian Stacey <jhs@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	hylafax
PORTVERSION=	4.2.5
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fax software

BUILD_DEPENDS=	${LOCALBASE}/lib/afm/Courier:${PORTSDIR}/print/afm \
		gawk:${PORTSDIR}/lang/gawk

# no dependency on ghostscript because we don't know which
# version the user prefers
LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg

RUN_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

DIST_SUBDIR=	hylafax

CONFIGURE_ARGS=	--with-INSTALL="" \
		--with-LIBTIFF="-L${LOCALBASE}/lib -ltiff -ljpeg" \
		--with-ZLIB=no --with-LIBZ=-lz --with-ZLIBINC=none \
		--with-TIFFINC="${LOCALBASE}/include" \
		--with-GCOPTS=" " --with-GCXXOPTS=" " \
		--with-REGEX=no --with-LIBREGEX='' --with-REGEXINC=none \
		--with-DIR_HTML="${DOCSDIR}" \
		--with-AWK="${LOCALBASE}/bin/gawk"

SUB_FILES=	pkg-message hylafax.sh.sample

# Defaults to "North American Letter".  Use "ISO A4" for A4.
.if defined(PAGESIZE)
CONFIGURE_ARGS+=--with-PAGESIZE="${PAGESIZE}"
.endif

# Want PAM?
.if defined(WITHOUT_PAM)
CONFIGURE_ARGS+=--disable-pam
.endif

# Want HTML documentation?
.if defined(WITH_HTMLDOC)
CONFIGURE_ARGS+=--with-HTML=yes
PLIST_SUB+=	PORTDOCS=""
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

.if defined(PACKAGE_BUILDING) || defined(BATCH)
CONFIGURE_ARGS+=--nointeractive
.endif

MAKE_ARGS+=	OPTIMIZER="" -EOPTIMIZER
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	ENVOPTS="${CFLAGS}"

MAN1=	edit-faxcover.1 faxalter.1 faxcover.1 faxmail.1 faxrm.1 faxstat.1 \
	hylafax-client.1 sendfax.1 sendpage.1 sgi2fax.1 textfmt.1

MAN5=	callid.5f destctrls.5f dialrules.5f doneq.5f hosts.hfaxd.5f \
	hylafax-config.5f hylafax-info.5f hylafax-log.5f hylafax-server.5f \
	hylafax-shutdown.5f pagermap.5f pagesizes.5f recvq.5f sendq.5f \
	status.5f tsi.5f typerules.5f xferfaxlog.5f

MAN8=	choptest.8c cqtest.8c dialtest.8c faxabort.8c faxaddmodem.8c \
	faxadduser.8c faxanswer.8c faxconfig.8c faxcron.8c faxdeluser.8c \
	faxgetty.8c faxinfo.8c faxlock.8c faxmodem.8c faxq.8c \
	faxqclean.8c faxquit.8c faxrcvd.8c faxsend.8c faxsetup.8c faxstate.8c \
	faxwatch.8c hfaxd.8c mkcover.8c notify.8c pagesend.8c pdf2fax.8c \
	pollrcvd.8c ps2fax.8c recvstats.8c tagtest.8c tiff2fax.8c \
	tiffcheck.8c tsitest.8c wedged.8c xferfaxstats.8c

SUID_EXES=	${PREFIX}/sbin/faxgetty ${PREFIX}/sbin/faxq \
		${PREFIX}/bin/faxrm ${PREFIX}/bin/faxalter

.include <bsd.port.pre.mk>

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
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,-O hfaxd.conf,-O hfaxd.conf-dist,' \
		${WRKSRC}/hfaxd/Makefile.in
	${REINPLACE_CMD} -e 's,-O typerules,-O typerules-dist -src typerules,' \
		-e 's,-O pagesizes,-O pagesizes-dist -src pagesizes,' \
		${WRKSRC}/util/Makefile.in

post-install:
	${CHOWN} uucp ${SUID_EXES}
	${CHMOD} 4555 ${SUID_EXES}
	${INSTALL_SCRIPT} ${WRKDIR}/hylafax.sh.sample ${PREFIX}/etc/rc.d
.for f in hfaxd.conf pagesizes typerules
	if [ ! -f ${PREFIX}/lib/fax/${f} ]; then ${CP} -p ${PREFIX}/lib/fax/${f}-dist ${PREFIX}/lib/fax/${f}; fi
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
