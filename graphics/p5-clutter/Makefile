# New ports collection makefile for:	p5-clutter
# Date created:				Dezember 27, 2008
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clutter
PORTVERSION=	0.8.2.0
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.clutter-project.org/sources/clutter-perl/0.8/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-perl-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Perl bindings to the Clutter OpenGL canvas

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.03:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Gtk2>=1.060:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo \
		p5-GStreamer>=0.09:${PORTSDIR}/multimedia/p5-GStreamer
LIB_DEPENDS=	clutter-glx-0.8:${PORTSDIR}/graphics/clutter \
		clutter-gst-0.8:${PORTSDIR}/multimedia/clutter-gst \
		clutter-cairo-0.8:${PORTSDIR}/graphics/clutter-cairo \
		clutter-gtk-0.8:${PORTSDIR}/graphics/clutter-gtk

PERL_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/Clutter-0.820

MAN3=	Clutter.3 Clutter::Actor.3 Clutter::ActorBox.3 Clutter::Alpha.3 \
	Clutter::Angle.3 Clutter::Backend.3 Clutter::Behaviour.3 \
	Clutter::Behaviour::Bspline.3 Clutter::Behaviour::Depth.3 \
	Clutter::Behaviour::Ellipse.3 Clutter::Behaviour::Opacity.3 \
	Clutter::Behaviour::Path.3 Clutter::Behaviour::Rotate.3 \
	Clutter::Behaviour::Scale.3 Clutter::ChildMeta.3 \
	Clutter::Cogl.3 Clutter::Cogl::Handle.3 \
	Clutter::Cogl::Texture.3 Clutter::Color.3 \
	Clutter::Container.3 Clutter::Container::ForeachFunc.3 \
	Clutter::Cookbook.3 Clutter::Effect.3 Clutter::Entry.3 \
	Clutter::Event.3 Clutter::Event::Button.3 Clutter::Event::Crossing.3 \
	Clutter::Event::Key.3 Clutter::Event::Motion.3 Clutter::Event::Scroll.3 \
	Clutter::Event::StageState.3 Clutter::Fixed.3 Clutter::Geometry.3 \
	Clutter::Group.3 Clutter::Gst.3 Clutter::Gst::Audio.3 \
	Clutter::Gst::VideoSink.3 Clutter::Gst::VideoTexture.3 Clutter::Gtk.3 \
	Clutter::Keysyms.3 Clutter::Knot.3 Clutter::Label.3 Clutter::ListModel.3 \
	Clutter::Media.3 Clutter::Model.3 Clutter::Model::Iter.3 \
	Clutter::ParamSpec.3 Clutter::Rectangle.3 Clutter::Score.3 \
	Clutter::Script.3 Clutter::Shader.3 Clutter::Stage.3 Clutter::StageManager.3 \
	Clutter::Texture.3 Clutter::Texture::Cairo.3 Clutter::Texture::Clone.3 \
	Clutter::Threads.3 Clutter::Timeline.3 Clutter::Units.3 \
	Clutter::Vertex.3 Clutter::index.3 Clutter::main.3 Clutter::version.3 \
	Gtk2::ClutterEmbed.3 Gtk2::ClutterUtil.3 Gtk2::ClutterTexture.3

.include <bsd.port.mk>
