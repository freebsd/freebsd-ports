# Created by: Seiichirou Hiraoka
# $FreeBSD$

PORTNAME=	namazu
PORTVERSION=	1.3.0.11
PORTREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	http://www.namazu.org/stable/ \
		LOCAL/flathill

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Search engine software intended for easy use

BUILD_DEPENDS=	kakasi:japanese/kakasi \
		nkf:japanese/nkf
RUN_DEPENDS=	kakasi:japanese/kakasi \
		nkf:japanese/nkf

USES=		perl5 shebangfix
SHEBANG_FILES=	../contrib/bnamazu
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/namazu \
		${STAGEDIR}${PREFIX}/namazu/bin/namazu

post-patch:
	@${REINPLACE_CMD} '/^int main/ s|uchar|char|' ${WRKSRC}/namazu.c

.include <bsd.port.mk>
