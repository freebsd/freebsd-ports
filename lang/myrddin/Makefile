# $FreeBSD$

PORTNAME=	myrddin
PORTVERSION=	0.2.2
CATEGORIES=	lang
MASTER_SITES=	http://myrlang.org/releases/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Myrddin Compiler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

USES=	gmake

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix "${PREFIX}"
TEST_TARGET=	check
WRKSRC=	${WRKDIR}/mc

OPTIONS_DEFINE=	DEBUG VIM
OPTIONS_DEFAULT=	VIM
OPTIONS_SUB=	yes

VIM_DESC=	Install Vim plugin

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

post-install-VIM-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/vimfiles
	@cd ${WRKSRC}/support/vim && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/vim/vimfiles

.include <bsd.port.mk>
