PORTNAME=	svntrac
PORTREVISION=	5

COMMENT=	Web-Based Bug And Patch-Set Tracking System For Subversion

.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS=	subversion-lts>0:devel/subversion-lts
.else
RUN_DEPENDS=	subversion>0:devel/subversion
.endif

MASTERDIR=	${.CURDIR}/../cvstrac
MAKE_ARGS=	APPNAME=svntrac
PKGMESSAGE=	${.CURDIR}/pkg-message

CPE_PRODUCT=	cvstrac

.include "${MASTERDIR}/Makefile"
