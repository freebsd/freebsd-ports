# Created by: Sofian Brabez <sbrabez@gmail.com>

PORTNAME=	colorgcc
PORTVERSION=	1.4.5
CATEGORIES=	devel misc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl script to colorize the terminal output of GCC

LICENSE=	GPLv2

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	colorgcc

SHEBANG_FILES=	colorgcc.pl

NO_BUILD=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	bin/${PORTNAME} \
		share/examples/${PORTNAME}/${PORTNAME}rc

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}rc.txt \
		${STAGEDIR}${EXAMPLESDIR}/${PORTNAME}rc

.include <bsd.port.mk>
