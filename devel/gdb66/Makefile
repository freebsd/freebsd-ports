# ex:ts=8
# Ports collection makefile for:	GDB 5.1
# Date created:				30 March 2001
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

SNAPDATE=	2004-08-03
SNAPVER=	${SNAPDATE:S/-//g}

PORTNAME=	gdb
PORTVERSION=	6
PORTREVISION=	${SNAPVER}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	gdb/snapshots/current obrien
DISTNAME=	gdb+dejagnu-weekly-${SNAPVER}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	obrien
#PATCHFILES=	gdb60_xfree-loadmod.diff

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	GNU GDB 6

WRKSRC=		${WRKDIR}/${DISTNAME:S/-weekly//}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=6
CFLAGS+=	-DRL_NO_COMPAT -DKGDB

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on 4.x"
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64" || ${ARCH} == "ia64"
PLIST_SUB+=	NO_NATIVE_GDB=""
post-install:
	cd ${PREFIX}/bin ; ${LN} -sf gdb${PORTVERSION} gdb
.else
PLIST_SUB+=	NO_NATIVE_GDB="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/$$/ [GDB v6.x for FreeBSD]/' \
		${WRKSRC}/gdb/version.in
	@${REINPLACE_CMD} -e 's/^READLINE/#READLINE/' \
		-e 's/^readline/#readline/' \
		${WRKSRC}/gdb/Makefile.in
	${ECHO} 'READLINE = -lreadline' >> ${WRKSRC}/gdb/Makefile.in

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect readline sim tcl texinfo
.for f in freebsd-uthread.c kvm-fbsd.c kvm-fbsd-${ARCH}.h
	${LN} -sf ${FILESDIR}/${f} ${WRKSRC}/gdb/${f:C/-${ARCH}//}
.endfor
	${LN} -sf ${FILESDIR}/nm-fbsd.h ${WRKSRC}/gdb/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${PREFIX}/bin/${PORTNAME}${PORTVERSION:S/.//g}
cklatest:
	ncftpls \
	    ftp://sources.redhat.com/pub/${MASTER_SITE_SUBDIR}/  \
	    | ${GREP} gdb+dejagnu-weekly

.include <bsd.port.post.mk>
