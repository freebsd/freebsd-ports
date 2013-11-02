# Created by: Dmitry Karasik (<dk@catpipe.net>)
# $FreeBSD$

PORTNAME=	HTML_QuickForm_Controller
PORTVERSION=	1.0.9
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The add-on to HTML_QuickForm that allows building of multipage forms

BUILD_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm
RUN_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm

PEAR_AUTOINSTALL=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
