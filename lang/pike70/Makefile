# New ports collection makefile for:	pike
# Date created:		16 Jan 1999
# Whom:			vns@delta.odessa.ua
#
# $FreeBSD$
#

PORTNAME=	pike
PORTVERSION=	7.0.361
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.oav.net/pike/7.0/	\
		ftp://ftp.oav.net/caudium/pkg/FreeBSD/distfiles/ \
		ftp://ftp.caudium.net/caudium/snapshots/pike/7.0/ \
		http://grendel.firewall.com/caudium-pkg/
DISTNAME=	pike-${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	A dynamic programming language with a syntax similar to C++

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison/

WRKSRC=		${WRKDIR}/${DISTNAME}/src/

IS_INTERACTIVE=	yes
GNU_CONFIGURE=  yes

.include <bsd.port.pre.mk>

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.else
CONFIGURE_ARGS?= \
	--without-ttflib \
	--without-gdbm \
	--without-mysql \
	--without-postgresql \
	--without-msql \
	--without-jpeg
.endif
CONFIGURE_ARGS+= --without-debug --with-poll --with-oob --with-max-fds=10000 --without-GTK
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

pre-fetch:
.if !defined(BATCH)
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.pike
.endif

pre-configure:
	@${ECHO} ${CONFIGURE_ARGS}

pre-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}pike ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}hilfe ${PREFIX}/bin

.include <bsd.port.post.mk>
