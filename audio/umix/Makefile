PORTNAME=	umix
PORTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced tool for adjusting soundcard mixers, replacement for aumix
WWW=		https://umix.sourceforge.net/

USES=		alias ncurses
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/umix \
		share/man/man1/umix.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|="/etc"|="$${prefix}/etc"|g' ${WRKSRC}/configure

.include <bsd.port.mk>
