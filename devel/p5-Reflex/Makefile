# New ports collection makefile for:	p5-Reflex
# Date created:				2011-03-16
# Whom:					Jase Thew <freebsd@beardz.net>
#
# $FreeBSD$
#

PORTNAME=	Reflex
PORTVERSION=	0.099
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RCAPUTO
PKGNAMEPREFIX=	p5-

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Class library for flexible, reactive programs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-POE>=1.294:${PORTSDIR}/devel/p5-POE \
		p5-Moose>=2.0203:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Role-Parameterized>=0.23:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

MAN3=		MooseX::Role::Reactive.3 \
		Reflex.3 \
		Reflex::Acceptor.3 \
		Reflex::Base.3 \
		Reflex::Callback.3 \
		Reflex::Callback::CodeRef.3 \
		Reflex::Callback::Method.3 \
		Reflex::Callback::Promise.3 \
		Reflex::Callbacks.3 \
		Reflex::Client.3 \
		Reflex::Codec::Message.3 \
		Reflex::Codec::Message::Datagram.3 \
		Reflex::Codec::Message::Eof.3 \
		Reflex::Codec::Message::Stream.3 \
		Reflex::Collection.3 \
		Reflex::Connector.3 \
		Reflex::Decoder::Line.3 \
		Reflex::Eg.3 \
		Reflex::Eg::Inheritance::Moose.3 \
		Reflex::Eg::Inheritance::Plain.3 \
		Reflex::Encoder::Line.3 \
		Reflex::Event.3 \
		Reflex::Event::Datagram.3 \
		Reflex::Event::EOF.3 \
		Reflex::Event::Error.3 \
		Reflex::Event::FileHandle.3 \
		Reflex::Event::Flushed.3 \
		Reflex::Event::Interval.3 \
		Reflex::Event::Octets.3 \
		Reflex::Event::POE.3 \
		Reflex::Event::Postback.3 \
		Reflex::Event::SigChild.3 \
		Reflex::Event::Signal.3 \
		Reflex::Event::Socket.3 \
		Reflex::Event::Time.3 \
		Reflex::Event::Timeout.3 \
		Reflex::Event::ValueChange.3 \
		Reflex::Event::Wakeup.3 \
		Reflex::Filehandle.3 \
		Reflex::Interval.3 \
		Reflex::PID.3 \
		Reflex::POE::Event.3 \
		Reflex::POE::Postback.3 \
		Reflex::POE::Session.3 \
		Reflex::POE::Wheel.3 \
		Reflex::POE::Wheel::Run.3 \
		Reflex::Role.3 \
		Reflex::Role::Accepting.3 \
		Reflex::Role::Collectible.3 \
		Reflex::Role::Connecting.3 \
		Reflex::Role::Decoding.3 \
		Reflex::Role::Decoding::Datagram.3 \
		Reflex::Role::Decoding::Stream.3 \
		Reflex::Role::Encoding.3 \
		Reflex::Role::InStreaming.3 \
		Reflex::Role::Interval.3 \
		Reflex::Role::OutStreaming.3 \
		Reflex::Role::PidCatcher.3 \
		Reflex::Role::Reactive.3 \
		Reflex::Role::Readable.3 \
		Reflex::Role::Reading.3 \
		Reflex::Role::Recving.3 \
		Reflex::Role::SigCatcher.3 \
		Reflex::Role::Streaming.3 \
		Reflex::Role::Timeout.3 \
		Reflex::Role::Wakeup.3 \
		Reflex::Role::Writable.3 \
		Reflex::Role::Writing.3 \
		Reflex::Signal.3 \
		Reflex::Stream.3 \
		Reflex::Timeout.3 \
		Reflex::Trait::EmitsOnChange.3 \
		Reflex::Trait::Observed.3 \
		Reflex::Trait::Watched.3 \
		Reflex::UdpPeer.3 \
		Reflex::Wakeup.3

.include <bsd.port.pre.mk>

post-extract:
	@${RM} ${WRKSRC}/bench.pl
	@${REINPLACE_CMD} -e '/^bench.pl$$/d' ${WRKSRC}/MANIFEST

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}"
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/proto/ ${EXAMPLESDIR}/ttl/
	${INSTALL_SCRIPT} ${WRKSRC}/eg/*.pl ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/eg/*.pm ${EXAMPLESDIR}/
	cd ${WRKSRC}/eg/proto/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/proto/
	cd ${WRKSRC}/eg/ttl/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/ttl/
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}"
.endif

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.23:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.23:${PORTSDIR}/lang/p5-Scalar-List-Utils
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
