# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flite
PORTVERSION=	1.4
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/flite/packed/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-release

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Small run-time speech synthesis engine

OPTIONS_DEFINE=	DOCS

USES=		tar:bzip2 gmake desthack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared=yes
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

CFLAGS:=	${CFLAGS:N-O:N-O[0123456789]} -O0

post-patch:
	@${REINPLACE_CMD} -e 's|-pd|-p|g' ${WRKSRC}/main/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
