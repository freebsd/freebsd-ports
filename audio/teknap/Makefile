# New ports collection makefile for:	BWap napster client
# Date created:				29 Mar 2000
# Whom:					Carl Johan Madestrand
#
# $FreeBSD$
#

PORTNAME=	BWap
PORTVERSION=	1.3a
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.bitchx.com/pub/BWap/ \
		ftp://ukug.uk.freebsd.org/pub/lord_cj/

MAINTAINER=	calle.madestrand@norrgarden.se

WRKSRC=		${WRKDIR}/BWap
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix="${PREFIX}/share" \
		--bindir="${PREFIX}/bin" \
		--datadir="${PREFIX}/share" \
		--libdir="${PREFIX}/share"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

post-install:
	${MKDIR} ${PREFIX}/share/doc/BWap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/BWap
	@${ECHO}
	@${CAT} ${PKGDIR}/MESSAGE | ${SED} -e "s:%%PREFIX%%:${PREFIX}:g"
	@${ECHO}

.include <bsd.port.mk>
