# ports collection makefile for:	hylafax
# Date created:		19 Apr 1997
# Whom:			ports@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	hylafax
PORTVERSION=	4.1.5
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/source/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/afm/Courier:${PORTSDIR}/print/afm
# no dependency on ghostscript because we don't know which
# version the user prefers
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg

DIST_SUBDIR=	hylafax

CONFIGURE_ARGS=	--with-INSTALL="" \
		--with-LIBTIFF="-L${LOCALBASE}/lib -ltiff -ljpeg" \
		--with-ZLIB=no --with-LIBZ=-lz --with-ZLIBINC=none \
		--with-TIFFINC="${LOCALBASE}/include" \
		--with-GCOPTS=" " --with-GCXXOPTS=" " \
		--with-REGEX=no --with-LIBREGEX='' --with-REGEXINC=none \
		--with-DIR_HTML="${LOCALBASE}/share/doc/hylafax"
# Defaults to "North American Letter".  Use "ISO A4" for A4.
.ifdef PAGESIZE
CONFIGURE_ARGS+=--with-PAGESIZE="${PAGESIZE}"
.endif
.if defined(PACKAGE_BUILDING) || defined(BATCH)
CONFIGURE_ARGS+=--nointeractive
.endif
MAKE_ARGS+=	OPTIMIZER="" -EOPTIMIZER

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	ENVOPTS="${CFLAGS}"

MAN1=	hylafax-client.1 faxalter.1 faxcover.1 faxmail.1 \
	faxrm.1 faxstat.1 sendfax.1 \
	sendpage.1 sgi2fax.1 textfmt.1
MAN5=	pagesizes.5f typerules.5f hosts.hfaxd.5f xferfaxlog.5f \
	cid.5f doneq.5f hylafax-config.5f destctrls.5f dialrules.5f \
	hylafax-info.5f hylafax-log.5f pagermap.5f recvq.5f sendq.5f \
	hylafax-server.5f hylafax-shutdown.5f status.5f tsi.5f
MAN8=	cqtest.8c choptest.8c dialtest.8c faxabort.8c faxaddmodem.8c \
	faxadduser.8c faxanswer.8c faxconfig.8c faxdeluser.8c faxmodem.8c \
	faxstate.8c faxcron.8c faxgetty.8c faxinfo.8c faxq.8c faxqclean.8c \
	faxquit.8c faxrcvd.8c faxsend.8c faxsetup.8c faxwatch.8c hfaxd.8c \
	mkcover.8c notify.8c pagesend.8c pdf2fax.8c pollrcvd.8c ps2fax.8c \
	recvstats.8c \
	tagtest.8c tiff2fax.8c tiffcheck.8c tsitest.8c wedged.8c \
	xferfaxstats.8c

SUID_EXES=	${PREFIX}/sbin/faxgetty ${PREFIX}/sbin/faxq \
		${PREFIX}/bin/faxrm ${PREFIX}/bin/faxalter

post-extract:
	${RM} -rf ${WRKSRC}/zlib ${WRKSRC}/regex

post-install:
	${CHOWN} uucp ${SUID_EXES}
	${CHMOD} 4555 ${SUID_EXES}
	@if [ ! -f ${PREFIX}/etc/rc.d/hylafax.sh.sample ]; then	\
		${SED} 's^/usr/local^${PREFIX}^g' \
			< ${FILESDIR}/hylafax.sh.sample \
			> ${PREFIX}/etc/rc.d/hylafax.sh.sample;	\
	fi
	@${SED} 's^/usr/local^${PREFIX}^g' < ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${LOCALBASE} != /usr/local
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
post-patch:
	${REINPLACE_CMD} -e 's^/usr/local^${LOCALBASE}^g' \
		`${FIND} ${WRKSRC} -type f -print0 | \
			${XARGS} -0 ${GREP} -F -l --mmap /usr/local`
.endif

.include <bsd.port.post.mk>
