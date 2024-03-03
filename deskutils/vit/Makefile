PORTNAME=	vit
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://taskwarrior.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based interface to taskwarrior
WWW=		https://tasktools.org/projects/vit.html

LICENSE=	GPLv3+

BUILD_DEPENDS=	p5-Curses>=0:devel/p5-Curses \
		task:deskutils/taskwarrior
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	vit.pl
GNU_CONFIGURE=	yes
ALL_TARGET=	build

PLIST_FILES=	bin/vit \
		etc/vit-commands \
		share/man/man1/vit.1.gz \
		share/man/man5/vitrc.5.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/commands ${STAGEDIR}${PREFIX}/etc/vit-commands
	${INSTALL_MAN} ${WRKSRC}/vit.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/vitrc.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
