# $FreeBSD$

PORTNAME=	kyua
PORTVERSION=	20140215
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	jmmv@FreeBSD.org
COMMENT=	Kyua (automated testing framework) - Meta-port

LICENSE=	BSD

RUN_DEPENDS+=	${LOCALBASE}/bin/atf2kyua:${PORTSDIR}/devel/kyua-atf-compat
RUN_DEPENDS+=	${LOCALBASE}/bin/kyua:${PORTSDIR}/devel/kyua-cli
RUN_DEPENDS+=	${LOCALBASE}/libexec/kyua-atf-tester:${PORTSDIR}/devel/kyua-testers

NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

pre-everything::
	@${ECHO_MSG} "This is a meta-port, meaning that it just depends on its subparts of the port."
	@${ECHO_MSG} "It won't build and install all the parts until you have typed make install"

.include <bsd.port.pre.mk>

.if make(package)
.if !defined(DEPENDS_TARGET:Mpackage) || empty(DEPENDS_TARGET:Mpackage)
DEPENDS_TARGET="package"
.endif
.endif

.include <bsd.port.post.mk>
