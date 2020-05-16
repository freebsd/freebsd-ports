# Created by: tonym
# $FreeBSD$

PORTNAME=	ncbi-toolkit
DISTVERSION=	2017.01.06	# containing BLAST v2.2.27 (? is this true)
PORTREVISION=	5
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ncbi.nlm.nih.gov/toolbox/ncbi_tools/old/${PORTVERSION:S/.//g}/
DISTNAME=	ncbi
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	NCBI development toolkit, including BLAST 2 and GenBank/Entrez support

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libgmp.so:math/gmp \
		libgnutls.so:security/gnutls \
		libhogweed.so:security/nettle \
		libidn2.so:dns/libidn2 \
		libnettle.so:security/nettle \
		libp11-kit.so:security/p11-kit \
		libpng.so:graphics/png \
		libtasn1.so:security/libtasn1 \
		libtspi.so:security/trousers \
		libunistring.so:devel/libunistring

USES=		gettext-runtime iconv jpeg motif xorg
USE_XORG=	x11 xau xext xft xmu xrender xt

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/make/makedis.csh
	@${REINPLACE_CMD} -e \
		'/^NCBI_CC/s|=.*|= ${CC}| ; \
		 /^NCBI_LDFLGS1/s|=.*|= ${LDFLAGS}| ; \
		 /^NCBI_OPTFLAG/s|= .*|= ${CFLAGS}| ; \
		 /^NCBI_VIBLIBS/s|-lXp\ || ; \
		 /^NCBI_DISTVIBLIBS/s|-lXp\ || ; \
		 s|-I/usr/X11R6/include||g ; \
		 s|-L/usr/X11R6/lib||g ; \
		 s|/usr/local|${LOCALBASE}|g ; \
		 s|-Wl,-Bstatic|| ; \
		 s|-Wl,-Bdynamic||' ${WRKSRC}/platform/freebsd.ncbi.mk
	@${REINPLACE_CMD} -e 's/%%ICONV_LIB%%/${ICONV_LIB}/' \
		${WRKSRC}/make/makeall.unx ${WRKSRC}/make/makenet.unx

# the ncbi-toolkit provides a shell script to drive the build
# and we use it

do-build:
	@cd ${WRKDIR} && ./${DISTNAME}/make/makedis.csh

# the ncbi-toolkit does not provide an install target
# we thus roll our own

do-install:
	cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} * ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${DISTNAME}
	cd ${WRKSRC}/lib && ${INSTALL_DATA} *.a \
		${STAGEDIR}${PREFIX}/lib/${DISTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${DISTNAME}/connect
	cd ${WRKSRC}/include && ${INSTALL_DATA} *.h \
		${STAGEDIR}${PREFIX}/include/${DISTNAME}
	cd ${WRKSRC}/include/connect && ${INSTALL_DATA} *.h \
		${STAGEDIR}${PREFIX}/include/${DISTNAME}/connect
	cd ${WRKSRC}/doc/man && ${INSTALL_MAN} * \
		${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/data && ${INSTALL_DATA} * ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} '-not ( -name man -o -path ./man\/* )')

.include <bsd.port.mk>
