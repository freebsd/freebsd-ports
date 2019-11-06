# $FreeBSD$

PORTNAME=	charybdis
PORTVERSION=	3.5.3
CATEGORIES=	irc net
MASTER_SITES=	http://distfiles.charybdis.io/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Powerful IRC daemon, based on ircd-ratbox

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips=		Does not build: undefined reference to le32toh
BROKEN_mips64=		Does not build: undefined reference to le32toh
BROKEN_powerpc64=	Does not build: undefined reference to le32toh

CONFLICTS=	ircd-ratbox-[0-9]* ircd-ratbox-devel-[0-9]* \
		nefarious-[0-9]* ircd-hybrid-[0-9]* \
		ptlink-ircd-[0-9]* bnc-[0-9]* \
		whois-[0-9]* undernet-ircu-[0-9]* \
		ru-ircd-hybrid-[0-9]* \

USES=		libtool pathfix ssl tar:bz2
USE_RC_SUBR=	${PORTNAME}
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USERS=		ircd
GROUPS=		ircd
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR} \
		--with-rundir=/var/run \
		--enable-fhs-paths \
		--enable-kqueue

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ircd.motd \
		${STAGEDIR}${ETCDIR}/ircd.motd.sample

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libratbox.so

.include <bsd.port.mk>
