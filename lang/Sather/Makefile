# ex:ts=8
# Ports collection makefile for:  Sather
# Date created:			  Mon Oct 31 22:04:12 PST 1994
# Whom:				  hsu
#
# $FreeBSD$
#

PORTNAME=	sather
PORTVERSION=	1.2.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	sather

MAINTAINER=	obrien@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libgc.a:${PORTSDIR}/devel/boehm-gc

USE_GMAKE=	yes
ALL_TARGET=	full
MAN1=		sacomp.1

pre-configure:
	@${PERL} -pi.in \
		-e "s:%%CC%%:${CC}:g			;" \
	        -e "s:%%CFLAGS%%:${CFLAGS}:g		;" \
	        -e "s:%%LOCALBASE%%:${LOCALBASE}:g	;" \
	        -e "s:%%GMAKE%%:${GMAKE}:g		;" \
		${WRKSRC}/System/Common/CONFIG.proto

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/sacomp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Doc/man/man1/sacomp.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/doc/sather
	${INSTALL_DATA} ${WRKSRC}/Doc/License ${PREFIX}/share/doc/sather
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/sather
.for file in Bugs Changes Contributing FAQ programmer-manual.ps
	${INSTALL_DATA} ${WRKSRC}/Doc/${file} ${PREFIX}/share/doc/sather
.endfor
.endif

.include <bsd.port.mk>
