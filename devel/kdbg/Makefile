# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	kdbg
PORTVERSION=	2.5.6
CATEGORIES=	devel kde
MASTER_SITES=	SF/${PORTNAME}/Source%20Code/${PORTVERSION}

MAINTAINER=	thomas.sander@gmx.de
COMMENT=	Graphical user interface around gdb using KDE

LICENSE=	GPLv2

USES=		cmake kde:4
USE_KDE=	kdelibs automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build network xml dbus corelib gui svg
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if empty(PORT_OPTIONS:MNLS)
	${REINPLACE_CMD} -e 's|add_subdirectory(po)||g' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
