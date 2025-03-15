PORTNAME=	namazu
PORTVERSION=	1.3.0.11
PORTREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	http://www.namazu.org/stable/ \
		LOCAL/flathill

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Search engine software intended for easy use
WWW=		http://www.namazu.org

DEPRECATED=	Obsolete and superseded by namazu2, last release in 2000
EXPIRATION_DATE=2025-04-30

BUILD_DEPENDS=	kakasi:japanese/kakasi \
		nkf:japanese/nkf
RUN_DEPENDS=	kakasi:japanese/kakasi \
		nkf:japanese/nkf

USES=		cpe perl5 shebangfix
SHEBANG_FILES=	../contrib/bnamazu
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/namazu \
		${STAGEDIR}${PREFIX}/namazu/bin/namazu

post-patch:
	@${REINPLACE_CMD} '/^int main/ s|uchar|char|' ${WRKSRC}/namazu.c

.include <bsd.port.mk>
