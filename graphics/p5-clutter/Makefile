# New ports collection makefile for:	p5-clutter
# Date created:				Dezember 27, 2008
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clutter
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.clutter-project.org/sources/clutter-perl/${PORTVERSION:R}/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-perl-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Perl bindings to the Clutter OpenGL canvas

BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.03:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Pango.pm:${PORTSDIR}/x11-toolkits/p5-Pango \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo
LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter
RUN_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.03:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Pango.pm:${PORTSDIR}/x11-toolkits/p5-Pango \
		${SITE_PERL}/${PERL_ARCH}/Glib.pm:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo

DEPRECATED=	upstream distfile disappeard, and doesn't seem to be developed anymore
EXPIRATION_DATE=2011-11-06

MAKE_JOBS_UNSAFE=	yes

USE_BZIP2=	yes
PERL_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-perl-${PORTVERSION}

MAN3=	Clutter.3 Clutter::Actor.3 Clutter::ActorBox.3 Clutter::Alpha.3 \
	Clutter::Animation.3 Clutter::Backend.3 Clutter::Behaviour.3 \
	Clutter::Behaviour::Depth.3 Clutter::Behaviour::Ellipse.3 \
	Clutter::Behaviour::Opacity.3 Clutter::Behaviour::Path.3 \
	Clutter::Behaviour::Rotate.3 Clutter::Behaviour::Scale.3 \
	Clutter::BindingPool.3 Clutter::Cairo.3 Clutter::CairoTexture.3 \
	Clutter::ChildMeta.3 Clutter::Clone.3 Clutter::Cogl.3 \
	Clutter::Cogl::Color.3 Clutter::Cogl::Handle.3 \
	Clutter::Cogl::Material.3 Clutter::Cogl::MaterialLayer.3 \
	Clutter::Cogl::Matrix.3 Clutter::Cogl::Pango.3 Clutter::Cogl::Path.3 \
	Clutter::Cogl::Program.3 Clutter::Cogl::Shader.3 \
	Clutter::Cogl::Texture.3 Clutter::Color.3 Clutter::Container.3 \
	Clutter::Container::ForeachFunc.3 Clutter::Cookbook.3 Clutter::Event.3 \
	Clutter::Event::Button.3 Clutter::Event::Crossing.3 \
	Clutter::Event::Key.3 Clutter::Event::Motion.3 \
	Clutter::Event::Scroll.3 Clutter::Event::StageState.3 \
	Clutter::Geometry.3 Clutter::Group.3 Clutter::Interval.3 \
	Clutter::Keysyms.3 Clutter::Knot.3 Clutter::ListModel.3 \
	Clutter::Media.3 Clutter::Model.3 Clutter::Model::Iter.3 \
	Clutter::ParamSpec.3 Clutter::Path.3 Clutter::Path::Node.3 \
	Clutter::Rectangle.3 Clutter::Score.3 Clutter::Script.3 \
	Clutter::Shader.3 Clutter::Stage.3 Clutter::StageManager.3 \
	Clutter::Text.3 Clutter::Texture.3 Clutter::Threads.3 \
	Clutter::Timeline.3 Clutter::Units.3 Clutter::Vertex.3 \
	Clutter::index.3 Clutter::main.3 Clutter::version.3

.include <bsd.port.mk>
