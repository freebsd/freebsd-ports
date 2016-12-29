# $FreeBSD$

PORTNAME=	hyperv-is
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/${MSLINK}/
DISTNAME=	${DNAME}

MAINTAINER=	bsdic@microsoft.com
COMMENT=	FreeBSD Integration Service on Hyper-v

IGNORE=		does not support any actual FreeBSD release
DEPRECATED=	does not support any actual FreeBSD release
EXPIRATION_DATE=2017-03-01

ONLY_FOR_ARCHS=	amd64 i386

USES=		kmod uidfix
BIS=		${PORTVERSION}
MSBASE=		FreeBSDonHyper-V/Hyperv-Ports/raw/hyperv-is-master
MSLINK=		${MSBASE}/BIS-${BIS}/FreeBSD-${OSREL}/ports
MAKE_ARGS=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man
PKGMESSAGE=	${FILESDIR}/${PMSG}

.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		${OPSYS} not supported
.endif

.if ${OSREL} == "10.0"
BIS=		1.0
PLIST_SUB=	A="@comment " B=""
PMSG=		pkg-message.B
.else
CC=		gcc -w
WRKSRC=		${WRKDIR}/hyperv-is-${PORTVERSION}
PLIST_SUB=	B="@comment " A=""
PMSG=		pkg-message.A
.endif

FILE_84=	hyperv-is-8.4.${BIS}
FILE_91=	hyperv-is-9.1.${BIS}
FILE_92=	hyperv-is-9.2.${BIS}
FILE_93=	hyperv-is-9.3.${BIS}
FILE_100=	hv-kvp-${BIS}
DNAME=		${FILE_${OSREL:S/.//}}

.if empty(DNAME)
IGNORE?=	OSREL ${OSREL} not supported
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/sbin/,${PREFIX}/sbin/,g" \
		${WRKSRC}/etc/rc.d/hv_kvpd

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX} \
		${STAGEDIR}/etc/rc.d \
		${STAGEDIR}/usr/local/hyperv/scripts

post-install:
	${RM} ${STAGEDIR}/boot/kernel/linker.hints
	${MV} ${STAGEDIR}/etc/rc.d/* ${STAGEDIR}${PREFIX}/etc/rc.d
.if ${PREFIX} != /usr/local
	${MV} ${STAGEDIR}/usr/local/* ${STAGEDIR}${PREFIX}
.endif

.include <bsd.port.post.mk>
