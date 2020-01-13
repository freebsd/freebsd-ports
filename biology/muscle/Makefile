# Created by: Motomichi Matsuzaki <mzaki@biol.s.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	muscle
PORTVERSION=	3.8.1551
CATEGORIES=	biology
MASTER_SITES=	http://www.drive5.com/muscle/
DISTNAME=	${PORTNAME}_src_${PORTVERSION}

MAINTAINER=	mzaki@e-mail.ne.jp
COMMENT=	MUltiple Sequence Comparison by Log-Expectation

LICENSE=	PD

USES=		dos2unix gmake
NO_WRKSUBDIR=	yes
DOS2UNIX_GLOB=	*.cpp

PLIST_FILES=	bin/muscle

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/muscle ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
