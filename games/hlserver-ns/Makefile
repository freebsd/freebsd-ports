# New ports collection makefile for:	Natural Selection Server
# Date created:				Tue Nov 12 03:27:08 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ns
PORTVERSION=	1.0.4
PORTREVISION=	1
MASTER_SITES=	http://bsd.gubkin.ru/myports/ \
		http://mirror.isp.net.au/ftp/pub/FreeBSD/distfiles/
DISTFILES=	ns_v1_linux_dedicated_server.tar.gz \
		ns-v${PORTVERSION:S/.//g}.zip
EXTRACT_ONLY=	ns_v1_linux_dedicated_server.tar.gz

EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Half-Life mod Natural Selection full server package for Linux

slaveport-post-extract:
	@cd ${WRKSRC} && ${UNZIP_CMD} -a -o -qq ${DISTDIR}/ns-v${PORTVERSION:S/.//g}.zip

HALFLIFE_PORT_MASTER=	${.CURDIR}/../hlserver-flf

.include "${HALFLIFE_PORT_MASTER}/Makefile"
