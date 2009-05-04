# New ports collection makefile for:	miau
# Date created:				23 Apr 2004
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		miau
PORTVERSION=		0.6.5
CATEGORIES=		irc ipv6
MASTER_SITES=		SF

MAINTAINER=		dhn@FreeBSD.org
COMMENT=		A fully featured easy to use IRC-bouncer

USE_BZIP2=		yes
USE_ICONV=		yes
GNU_CONFIGURE=		yes

INFO=			miau
MAN1=			miau.1

CONFIGURE_ARGS=		--enable-dccbounce \
			--enable-automode \
			--enable-releasenick \
			--enable-ctcp-replies \
			--enable-mkpasswd \
			--enable-uptime \
			--enable-chanlog \
			--enable-privlog \
			--enable-onconnect \
			--enable-empty-awaymsg \
			--enable-dumpstatus \
			--disable-dependency-tracking
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
			LDFLAGS="${LDFLAGS}" \
			LIBS="${LIBS}"

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,\$$datadir/doc/miau/examples,${EXAMPLESDIR},g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif

.include <bsd.port.mk>
