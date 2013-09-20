# Created by: Dmitry Karasik <dmitry@karasik.eu.org>
# $FreeBSD$

PORTNAME=	UI-Dialog
PORTVERSION=	1.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KCK
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl wrapper for the various dialog applications

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

RUN_DEPENDS=	${LOCALBASE}/bin/cdialog:${PORTSDIR}/devel/cdialog

OPTIONS_DEFINE=	KDE NEWT X11 ZENITY

USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN3=		UI::Dialog.3 \
		UI::Dialog::Backend.3 \
		UI::Dialog::Backend::ASCII.3 \
		UI::Dialog::Backend::CDialog.3 \
		UI::Dialog::Backend::GDialog.3 \
		UI::Dialog::Backend::KDialog.3 \
		UI::Dialog::Backend::Nautilus.3 \
		UI::Dialog::Backend::Whiptail.3 \
		UI::Dialog::Backend::XDialog.3 \
		UI::Dialog::Backend::XOSD.3 \
		UI::Dialog::Backend::Zenity.3 \
		UI::Dialog::Console.3 \
		UI::Dialog::GNOME.3 \
		UI::Dialog::Gauged.3 \
		UI::Dialog::KDE.3 \
		UI::Dialog::Screen::Menu.3

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKDE}
RUN_DEPENDS+=	${LOCALBASE}/bin/kdialog:${PORTSDIR}/x11/kde4-baseapps
.endif

.if ${PORT_OPTIONS:MNEWT}
RUN_DEPENDS+=	${LOCALBASE}/bin/whiptail:${PORTSDIR}/devel/newt
.endif

.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	${LOCALBASE}/bin/Xdialog:${PORTSDIR}/x11/xdialog
.endif

.if ${PORT_OPTIONS:MZENITY}
RUN_DEPENDS+=	${LOCALBASE}/bin/zenity:${PORTSDIR}/x11/zenity
.endif

post-patch:
	@${REINPLACE_CMD} -e "/self->{'_opts'}->{'bin'}/ s|dialog|c&|" ${WRKSRC}/lib/UI/Dialog/Backend/CDialog.pm

.include <bsd.port.mk>
