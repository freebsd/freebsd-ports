# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	colorgcc
PORTVERSION=	1.3.2
CATEGORIES=	devel misc
MASTER_SITES=	http://schlueters.de/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.txt
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Perl script to colorize the terminal output of GCC

RUN_DEPENDS=	p5-Term-ANSIColor>=0:devel/p5-Term-ANSIColor
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		shebangfix
SHEBANG_FILES=	colorgcc

PLIST_FILES=	bin/${PORTNAME} \
		share/examples/${PORTNAME}/${PORTNAME}rc
SUB_FILES=	pkg-message

NO_BUILD=yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${INSTALL_DATA} ${FILESDIR}/${PORTNAME}rc ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
