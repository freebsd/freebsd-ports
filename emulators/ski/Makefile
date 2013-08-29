# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	ski
PORTVERSION=	0.943l.2
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	# http://www.hpl.hp.com/research/linux/ski/
DISTNAME=	ski-0.943l-2.i386
EXTRACT_SUFX=	.rpm

MAINTAINER=	freebsd-ia64@FreeBSD.org
COMMENT=	HP's Ski IA-64 simulator

ONLY_FOR_ARCHS=	i386

NOTICE=		 -- please manually download ${DISTNAME}${EXTRACT_SUFX} from the HP site (http://www.hpl.hp.com/research/linux/ski/download.php) and put it in ${DISTDIR} first
RESTRICTED=	License restrictions disallow automatic downloads and redistribution of the software.

EXTRACT_CMD=		${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	#
NO_WRKSUBDIR=		yes
NO_BUILD=		yes
NO_MTREE=		yes
MAN1=		ski.1
MLINKS=		ski.1 bski.1  ski.1 xski.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nue/usr/bin/ski ${PREFIX}/bin
	brandelf -t Linux ${PREFIX}/bin/ski
.for SL in bski bskinc xski
	cd ${PREFIX}/bin ; ${LN} -sf ski ${SL}
.endfor
	${INSTALL_DATA} ${WRKSRC}/nue/usr/X11R6/lib/X11/app-defaults/XSki \
		${LOCALBASE}/lib/X11/app-defaults
	${INSTALL_MAN} ${WRKSRC}/usr/man/man1/ski.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/examples/ski
	${INSTALL_DATA} ${FILESDIR}/ia64.cmd ${PREFIX}/share/examples/ski
	${INSTALL_DATA} ${WRKSRC}/nue/usr/X11R6/lib/X11/app-defaults/XSki \
		${LOCALBASE}/lib/X11/app-defaults
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/usr/doc/ski-0.943l/* ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	${NOTICE}
.endif

.include <bsd.port.post.mk>
