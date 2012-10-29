# $FreeBSD$

PORTNAME=	atf
PORTVERSION=	0.16
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	namor@hemio.de
COMMENT=	Automated Testing Framework

LICENSE=	BSD

USE_LDCONFIG=	yes

PROJECTHOST=	kyua

MAN1=		atf-check.1 \
		atf-sh.1 \
		atf-test-program.1
MAN3=		atf-c-api.3 \
		atf-c++-api.3 \
		atf-sh-api.3
MAN4=		atf-test-case.4

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000021
IGNORE=	is already in the base system
.endif

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e 's|install-docDATA[^:]||' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|@atf_pkgconfigdir@|${PREFIX}/libdata/pkgconfig|' \
	  ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
