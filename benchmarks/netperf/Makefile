# New ports collection makefile for: netperf
# Date created:		19 July 1996
# Whom:			koshy
#
# $FreeBSD$
#

PORTNAME=	netperf
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	benchmarks ipv6
MASTER_SITES=	ftp://ftp.cup.hp.com/dist/networking/benchmarks/netperf/%SUBDIR%/
MASTER_SITE_SUBDIR=. archive
DISTNAME=	netperf-2.2pl2

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	netperf-22pl2-v6-20030121.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sumikawa@FreeBSD.org

MAKEFILE=	makefile
MAN1=		netperf.1 netserver.1

SCRIPTS=		arr_script snapshot_script tcp_range_script tcp_rr_script \
		tcp_stream_script udp_rr_script udp_stream_script

.include <bsd.port.pre.mk>

BUILD_DEFS+=	USE_INET6

post-patch:
.for i in ${SCRIPTS}
	@${MV} ${WRKSRC}/$i ${WRKSRC}/$i.pre-sed
	@${SED} -e 's^%%PREFIX%%^${PREFIX}^' ${WRKSRC}/$i.pre-sed > ${WRKSRC}/$i
.endfor

post-install:
	strip ${PREFIX}/netperf/netperf
	strip ${PREFIX}/netperf/netserver
	${INSTALL_MAN} ${WRKSRC}/netperf.man ${PREFIX}/man/man1/netperf.1
	${INSTALL_MAN} ${WRKSRC}/netserver.man ${PREFIX}/man/man1/netserver.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/netperf
	${INSTALL_DATA} ${WRKSRC}/netperf.ps ${PREFIX}/share/doc/netperf
	${GZIP_CMD} ${PREFIX}/share/doc/netperf/netperf.ps
.endif

.include <bsd.port.post.mk>
