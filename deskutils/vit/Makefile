# Created by: gahr
# $FreeBSD$

PORTNAME=	vit
PORTVERSION=	1.2
CATEGORIES=	deskutils
MASTER_SITES=	http://taskwarrior.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based interface to taskwarrior

LICENSE=	GPLv3

RUN_DEPENDS=	p5-Curses>=0:devel/p5-Curses \
		p5-Time-HiRes>=0:devel/p5-Time-HiRes \
		task:deskutils/taskwarrior
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	vit.pl
GNU_CONFIGURE=	yes
ALL_TARGET=	build

PLIST_FILES=	bin/vit \
		etc/vit-commands \
		man/man1/vit.1.gz \
		man/man5/vitrc.5.gz

post-patch:
	${REINPLACE_CMD} -e '1774,1778d' \
	    ${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/commands ${STAGEDIR}${PREFIX}/etc/vit-commands
	${INSTALL_MAN} ${WRKSRC}/vit.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/vitrc.5 ${STAGEDIR}${PREFIX}/man/man5

.include <bsd.port.mk>
