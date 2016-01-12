# $FreeBSD$

PORTNAME=	qucs
PORTVERSION=	0.0.18
CATEGORIES=	cad science
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Graphical circuit design and simulation tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_QT4=	moc_build uic_build rcc_build linguisttools_build \
		corelib gui xml svg script qt3support
USES=		bison gmake libtool shebangfix
SHEBANG_FILES=	contrib/ps2sp
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
