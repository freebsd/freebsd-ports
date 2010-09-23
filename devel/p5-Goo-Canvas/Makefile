# New ports collection makefile for:	p5-Goo-Canvas
# Date created:		2010-03-10
# Whom:			Sylvio Cesar Teixeira <sylvio@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Goo-Canvas
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Perl interface to the GooCanvas

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2
LIB_DEPENDS=	goocanvas.3:${PORTSDIR}/graphics/goocanvas \
		gdk_pixbuf_xlib.2:${PORTSDIR}/graphics/gdk-pixbuf
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2

MAKE_JOBS_UNSAFE=	yes

MAN1=		perltetris.pl.1 perlmine.pl.1
MAN3=		Goo::Canvas::Item.3 \
		Goo::Canvas.3 \
		Goo::Canvas::TextModel.3 \
		Goo::Canvas::Bounds.3 \
		Goo::Canvas::EllipseModel.3 \
		Goo::Canvas::Style.3 \
		Goo::Canvas::Ellipse.3 \
		Goo::Canvas::RectModel.3 \
		Goo::Canvas::index.3 \
		Goo::Canvas::PolylineModel.3 \
		Goo::Canvas::TableModel.3 \
		Goo::Canvas::ItemModel.3 \
		Goo::Canvas::Text.3 \
		Goo::Canvas::Polyline.3 \
		Goo::Canvas::Table.3 \
		Goo::Canvas::Image.3 \
		Goo::Canvas::ImageModel.3 \
		Goo::Canvas::PathModel.3 \
		Goo::Canvas::Group.3 \
		Goo::Canvas::GroupModel.3 \
		Goo::Canvas::Widget.3 \
		Goo::Cairo::Matrix.3 \
		Goo::Cairo::Pattern.3 \
		Goo::Canvas::Rect.3 \
		Goo::Canvas::LineDash.3 \
		Goo::Canvas::Path.3 \
		Goo::Canvas::Points.3 \
		Goo::Canvas::ItemSimple.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
