# New ports collection makefile for:    p5-DBD-ODBC
# Date created:				Nov 30 2001
# Whom:	      				Clive Lin <clive@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-ODBC
PORTVERSION=	1.19
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBD module interfacing the ODBC databases

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	-o ${LOCALBASE}

MAN3=		DBD::ODBC.3

.include <bsd.port.pre.mk>

.if defined(WITH_IODBC) && defined(WITH_UNIXODBC)
IGNORE=		selected mutually exclusive options: WITH_IODBC and WITH_UNIXODBC
.endif

.if !defined(WITH_IODBC) && !defined(WITH_UNIXODBC)
WITH_IODBC?=	yes
.endif

.if defined(WITH_IODBC)
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
MYODBC=	iodbc
.elif defined(WITH_UNIXODBC)
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
MYODBC=	unixodbc
post-configure:
	@${PERL} -pi -e 's/-lodbc/-lodbc ${PTHREAD_LIBS}/g;' \
		-e 's/$$/ ${PTHREAD_CFLAGS}/ if (/^CCFLAGS/);' \
		${WRKSRC}/Makefile
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README README.adabas README.informix

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/[[:<:]]our[[:>:]]/my/g' \
			  -e 's/^    @$$(NOOP)/	@$$(NOOP)/g' ${WRKSRC}/Makefile.PL
	@${PERL} -pi -e '$$_ .= "\$$myodbc = \"${MYODBC}\";" if ($$. == 365);' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
