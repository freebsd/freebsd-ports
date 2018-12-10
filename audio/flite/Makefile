# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flite
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/flite/packed/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-release

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Small run-time speech synthesis engine

OPTIONS_DEFINE=	DOCS

USES=		cpe desthack gmake tar:bzip2
CPE_VENDOR=	cmu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared=yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-pd|-pR|g' ${WRKSRC}/main/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/* ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
