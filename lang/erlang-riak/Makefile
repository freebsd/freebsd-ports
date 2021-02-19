# $FreeBSD$

PORTNAME=	erlang-riak
PORTVERSION=	16.b.02
CATEGORIES=	lang
MASTER_SITES=	http://s3.amazonaws.com/downloads.basho.com/erlang/
DISTNAME=	otp_src_${ERL_RELEASE}
DIST_SUBDIR=	erlang

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Custom erlang from Basho to be used with riak2

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: erts_allctr_wrappers
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: erts_allctr_wrappers

WRKSRC=		${WRKDIR}/otp_src_${ERL_RELEASE}

ERL_RELEASE=	R16B02-basho5

USES=		gmake ncurses perl5 ssl
USE_PERL5=	build
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-ssl=/usr \
		--disable-hipe \
		--enable-smp-support \
		--enable-threads \
		--enable-kernel-poll \
		--enable-sctp

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	error: invalid application of 'sizeof' to an incomplete type 'HMAC_CTX' (aka 'struct hmac_ctx_st')
BROKEN_FreeBSD_13=	error: invalid application of 'sizeof' to an incomplete type 'HMAC_CTX' (aka 'struct hmac_ctx_st')
.endif

.include <bsd.port.post.mk>
