# ex:ts=8
# Ports collection makefile for:  ski
# Date created:			  Mon Oct 15, 2001
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ski
PORTVERSION=	0.943l.2
CATEGORIES=	emulators
MASTER_SITES=	# ftp://www.software.hp.com/dist/swdepot/
DISTNAME=	ski-0.943l-2.i386
EXTRACT_SUFX=	.rpm

MAINTAINER=	freebsd-ia64@FreeBSD.org
COMMENT=	HP's Ski IA-64 simulator

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

ONLY_FOR_ARCHS=	i386

NOTICE=		 -- please manually download ${DISTNAME}${EXTRACT_SUFX} from the HP site (http://www.software.hp.com/products/LIA64/overview1a.htm) and put it in ${DISTDIR} first. License restrictions disallow automatic downloads and redistribution of the software.
NO_PACKAGE=	${NOTICE}
NO_CDROM=	${NOTICE}

EXTRACT_CMD=		rpm2cpio.pl
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|${CPIO} -idum
NO_WRKSUBDIR=		yes
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
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
		${X11BASE}/lib/X11/app-defaults
	${INSTALL_MAN} ${WRKSRC}/usr/man/man1/ski.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/examples/ski
	${INSTALL_DATA} ${FILESDIR}/ia64.cmd ${PREFIX}/examples/ski
	${INSTALL_DATA} ${WRKSRC}/nue/usr/X11R6/lib/X11/app-defaults/XSki \
		${X11BASE}/lib/X11/app-defaults
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/usr/doc/ski-0.943l/* ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	${NOTICE}
.endif

.include <bsd.port.post.mk>
