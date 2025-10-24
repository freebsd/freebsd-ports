PORTNAME=	nbd-client
DISTVERSION=	g20251024
CATEGORIES=	filesystems
PKGNAMESUFFIX=	-kmod

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Kernel NBD client for FreeBSD GEOM framework
WWW=		https://github.com/ryan-moeller/kernel-nbd-client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	format specifies type 'unsigned long' but the argument has type 'uint64_t' (aka 'unsigned long long')

ONLY_FOR_ARCHS=     amd64

USES=		kmod ssl uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	ryan-moeller
GH_PROJECT=	kernel-nbd-client
GH_TAGNAME=	ad543b462714b978f47a278a94a404d41b7ccf38
USE_RC_SUBR=	gnbd

MAKE_ENV=	GEOM_CLASS_DIR="${PREFIX}/lib/geom" \
		MANDIR="${PREFIX}/share/man/man"

SUB_FILES=	gnbd-bin

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/geom

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gnbd-bin ${STAGEDIR}${PREFIX}/sbin/gnbd
	${INSTALL_DATA} ${WRKSRC}/devd.conf.sample ${STAGEDIR}${PREFIX}/etc/devd/${PORTNAME}.conf.sample

.include <bsd.port.mk>
