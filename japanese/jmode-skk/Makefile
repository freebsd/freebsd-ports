# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-skk

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	XIM server for SKK input method

MASTERDIR=	${.CURDIR}/../../japanese/jmode
DESCR=		${.CURDIR}/pkg-descr

LIB_DEPENDS=	# empty
.if defined(WITH_DBSKKD) || exists(${LOCALBASE}/libexec/dbskkd-cdb)
RUN_DEPENDS=	${LOCALBASE}/libexec/dbskkd-cdb:${PORTSDIR}/japanese/dbskkd-cdb
.else
RUN_DEPENDS=	${LOCALBASE}/sbin/skkserv:${PORTSDIR}/japanese/skkserv
.endif

CONFIGURE_ARGS=	--with-skk

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
