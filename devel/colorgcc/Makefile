# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	colorgcc
PORTVERSION=	1.4.4
CATEGORIES=	devel misc

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Perl script to colorize the terminal output of GCC

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		shebangfix
SHEBANG_FILES=	colorgcc.pl
USE_GITHUB=	yes

GH_ACCOUNT=	olibre
GH_TAGNAME=	d844212

PLIST_FILES=	bin/${PORTNAME} \
		share/examples/${PORTNAME}/${PORTNAME}rc
SUB_FILES=	pkg-message

NO_BUILD=yes

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}rc ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
