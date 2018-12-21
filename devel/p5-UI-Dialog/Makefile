# Created by: Dmitry Karasik <dmitry@karasik.eu.org>
# $FreeBSD$

PORTNAME=	UI-Dialog
PORTVERSION=	1.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KCK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl wrapper for the various dialog applications

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-String-ShellQuote>=0:textproc/p5-String-ShellQuote
RUN_DEPENDS+=	cdialog:devel/cdialog

OPTIONS_DEFINE=	KDE NEWT ZENITY

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

KDE_RUN_DEPENDS=	kdialog:x11/kde4-baseapps
NEWT_RUN_DEPENDS=	whiptail:devel/newt
ZENITY_RUN_DEPENDS=	zenity:x11/zenity

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKDE}
DEPRECATED=	KDE4 is EOL
EXPIRATION_DATE=2018-12-31
.endif

post-patch:
	@${REINPLACE_CMD} -e "/self->{'_opts'}->{'bin'}/ s|dialog|c&|" ${WRKSRC}/lib/UI/Dialog/Backend/CDialog.pm

.include <bsd.port.mk>
