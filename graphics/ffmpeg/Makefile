# New ports collection makefile for:	ffmpeg
# Date created:		Tue Sep 25 15:52:09 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ffmpeg
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=		${WRKDIR}/${PORTNAME}

ONLY_FOR_ARCHS=	i386
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	MAKE="${GMAKE}" LOCALBASE="${LOCALBASE}"
CONFIGURE_ARGS= --cc="${CC}" --prefix="${PREFIX}" \
		--disable-grab

DOC_FILES=	README
# under subdir doc
DOC_DOCFILES=	FAQ README.dev README.tech \
		TODO bench.txt ffmpeg.txt \
		ffserver.txt
HEADER_FILES=	libavcodec/avcodec.h libavcodec/dsputil.h
LIB_FILES=	libav/libav.a libavcodec/libavcodec.a

.ifdef(WITHOUT_MMX)
CONFIGURE_ARGS+=	--disable-mmx
.endif

.ifndef(WITHOUT_MMX)
pre-everything::
	@${ECHO_MSG} "Define WITHOUT_MMX if your system does not support MMX"
.endif

post-patch:
	@${PERL} -pi -e "s!/etc/ffserver.conf!${PREFIX}/etc/ffserver.conf!g" \
		${WRKSRC}/ffserver.c

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in ${DOC_DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_DATA} ${WRKSRC}/doc/ffserver.conf \
		${PREFIX}/etc/ffserver.conf.sample
.for file in ${HEADER_FILES}
	@${MKDIR} ${PREFIX}/include/${file:H}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include/${file}
.endfor
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/${file:T}
.endfor

.include <bsd.port.mk>
