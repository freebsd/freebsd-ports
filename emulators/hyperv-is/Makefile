# $FreeBSD$

PORTNAME=	hyperv-is
PORTVERSION=	1.1
CATEGORIES=	emulators kld
MASTER_SITES=	https://github.com/${MSLINK}/
DISTNAME=	${DNAME}

MAINTAINER=	bsdic@microsoft.com
COMMENT=	FreeBSD Integration Service on Hyper-v

ONLY_FOR_ARCHS=	amd64 i386

USES+=		uidfix
BIS=		${PORTVERSION}
MSBASE=		FreeBSDonHyper-V/Hyperv-Ports/raw/hyperv-is-master
MSLINK=		${MSBASE}/BIS-${BIS}/FreeBSD-${OSREL}/ports
SUB_FILES=	${PMSG}

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
IGNORE=		OSREL ${OSREL} not supported
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}/boot/kernel \
		${STAGEDIR}/etc/rc.d \
		${STAGEDIR}/usr/share/man/man1 \
		${STAGEDIR}/usr/share/man/man4 \
		${STAGEDIR}/usr/share/man/man8 \
		${STAGEDIR}/usr/local/hyperv/scripts \
		${STAGEDIR}/usr/sbin
	${MV} ${WRKDIR}/${PMSG} ${WRKDIR}/pkg-message

post-install:
	${RM} ${STAGEDIR}/boot/kernel/linker.hints

.include <bsd.port.post.mk>
