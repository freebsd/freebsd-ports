# Created by: Sylvio Cesar Teixeira <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Goo-Canvas
PORTVERSION=	0.06
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Perl interface to the GooCanvas

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Cairo>=0:${PORTSDIR}/graphics/p5-Cairo \
		p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2
LIB_DEPENDS=	goocanvas:${PORTSDIR}/graphics/goocanvas
RUN_DEPENDS=	p5-Cairo>=0:${PORTSDIR}/graphics/p5-Cairo \
		p5-Glib2>=0:${PORTSDIR}/devel/p5-Glib2 \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2

USE_GNOME=	gdkpixbuf
USE_PERL5=	configure build run
USES=		perl5

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

.include <bsd.port.mk>
