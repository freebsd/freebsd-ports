# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	irssistats
PORTVERSION=	0.75
CATEGORIES=	irc
MASTER_SITES=	http://royale.zerezo.com/irssistats/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate IRC statistics based on irssi logs

MAKE_ARGS+=	DATADIR="${DATADIR}" DOCSDIR="${DOCSDIR}" EXAMPLESDIR="${EXAMPLESDIR}" PREFIX="${PREFIX}" \
		CC="${CC}" CFLAGS="${CFLAGS}"

MAN1=	irssistats.1
ALL_TARGET=	irssistats
INSTALL_TARGET=	install

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/etc/irssistats.conf|${PREFIX}/etc/irssistats.conf|g' ${WRKSRC}/irssistats.c

.if defined(NOPORTDOCS)
MAKE_ARGS+=	NOPORTDOCS="${NOPORTDOCS}"
.endif

.include <bsd.port.mk>
