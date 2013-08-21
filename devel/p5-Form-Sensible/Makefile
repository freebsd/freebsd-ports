# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Form-Sensible
PORTVERSION=	0.20.023
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sensible way to handle form based user interface

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Natural>=0:${PORTSDIR}/devel/p5-DateTime-Format-Natural \
		p5-DateTime-Set>=0:${PORTSDIR}/devel/p5-DateTime-Set \
		p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		Form::Sensible.3 \
		Form::Sensible::DelegateConnection.3 \
		Form::Sensible::Delegation.3 \
		Form::Sensible::FAQ.3 \
		Form::Sensible::Field.3 \
		Form::Sensible::Field::DateTime.3 \
		Form::Sensible::Field::FileSelector.3 \
		Form::Sensible::Field::LongText.3 \
		Form::Sensible::Field::Number.3 \
		Form::Sensible::Field::Select.3 \
		Form::Sensible::Field::SubForm.3 \
		Form::Sensible::Field::Text.3 \
		Form::Sensible::Field::Toggle.3 \
		Form::Sensible::Field::Trigger.3 \
		Form::Sensible::Form.3 \
		Form::Sensible::Overview.3 \
		Form::Sensible::Reflector.3 \
		Form::Sensible::Renderer.3 \
		Form::Sensible::Renderer::HTML.3 \
		Form::Sensible::Renderer::HTML::RenderedForm.3 \
		Form::Sensible::Validator.3 \
		Form::Sensible::Validator::Result.3

post-extract:
	@${RM} ${WRKSRC}/lib/Form/Sensible/Renderer/HTML/RenderedForm.pm.orig

#post-patch:
#	@${REINPLACE_CMD} -e 's|Form-Sensible|Form::Sensible|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
