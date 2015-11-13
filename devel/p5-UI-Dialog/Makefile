# Created by: Dmitry Karasik <dmitry@karasik.eu.org>
# $FreeBSD$

PORTNAME=	UI-Dialog
PORTVERSION=	1.09
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KCK
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl wrapper for the various dialog applications

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog

OPTIONS_DEFINE=	KDE NEWT X11 ZENITY

USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

KDE_RUN_DEPENDS=	kdialog:${PORTSDIR}/x11/kde4-baseapps
NEWT_RUN_DEPENDS=	whiptail:${PORTSDIR}/devel/newt
X11_RUN_DEPENDS=	Xdialog:${PORTSDIR}/x11/xdialog
ZENITY_RUN_DEPENDS=	zenity:${PORTSDIR}/x11/zenity

post-patch:
	@${REINPLACE_CMD} -e "/self->{'_opts'}->{'bin'}/ s|dialog|c&|" ${WRKSRC}/lib/UI/Dialog/Backend/CDialog.pm

.include <bsd.port.mk>
