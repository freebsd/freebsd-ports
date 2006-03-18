# New ports collection makefile for:	CHICKEN
# Date created:				31 December 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	chicken
PORTVERSION=	2.3
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.call-with-current-continuation.org/

MAINTAINER=	alejandro@varnet.biz
COMMENT=	A Scheme-to-C compiler

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		chicken-profile.1 chicken-setup.1 chicken.1 csc.1 csi.1
INFO=		chicken

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog INSTALL LICENSE NEWS README TASKS chicken.html chicken.pdf
.endif

OPTIONS=	PCRE "With PCRE support" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Coredump during build on ia64
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ENV+=	ac_cv_header_pcre_h=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/\(install-data-am: \)install-data-local/\1/' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|"/usr/local/include" ||' ${WRKSRC}/csc.scm.in

post-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
	@${MKDIR} ${EXAMPLESDIR}/benchmarks
	${INSTALL_DATA} ${WRKSRC}/benchmarks/* ${EXAMPLESDIR}/benchmarks
.endif

.include <bsd.port.post.mk>
