# Created by: Rodrigo Graeff <delphus@gmail.com>
# $FreeBSD$

PORTNAME=	ytnef
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	converters mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unpack data in MS Outlook TNEF format

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libytnef.so:devel/libytnef
RUN_DEPENDS=	p5-MIME-Tools>=0:mail/p5-MIME-Tools

USES=		perl5 shebangfix
SHEBANG_FILES=	src/ytnef/*.pl
USE_PERL5=	run
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS NEWS README
PLIST_FILES=	bin/ytnef bin/ytnefprint bin/ytnefprocess.pl

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share|${PREFIX}/share|' \
		${WRKSRC}/src/ytnef/*.pl

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
