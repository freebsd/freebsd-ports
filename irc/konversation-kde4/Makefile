# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	konversation
PORTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES=	irc kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	User friendly IRC client for KDE

LIB_DEPENDS=	libqca.so:devel/qca

USES=		cmake:outsource gettext kde:4 python:run shebangfix tar:xz
USE_KDE=	pimlibs automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build

SHEBANG_FILES=	data/scripts/bug \
		data/scripts/cmd \
		data/scripts/mail \
		data/scripts/media \
		data/scripts/sayclip \
		data/scripts/sysinfo \
		data/updaters/*.pl

.include <bsd.port.mk>
