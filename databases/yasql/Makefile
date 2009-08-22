# New ports collection makefile for:	yasql
# Date created:				22 February 2005
# Whom:	      				Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=		yasql
PORTVERSION=		1.83
CATEGORIES=		databases
MASTER_SITES=		SF

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Yet Another SQL*Plus Replacement

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/Oracle.pm:${PORTSDIR}/databases/p5-DBD-Oracle	\
		${SITE_PERL}/${PERL_ARCH}/Term/ReadLine/Gnu.pm:${PORTSDIR}/devel/p5-ReadLine-Gnu
RUN_DEPENDS=	${BUILD_DEPENDS}

# Time::HiRes is used for high resolution benchmarking
.if !defined(WITHOUT_HIRES)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.endif

# Text::CSV_XS is required to output CSV or input from CSV files
.if !defined(WITHOUT_CSV)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS
.endif

# Term::ReadKey is used for better input and output control
.if !defined(WITHOUT_READKEY)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey
.endif

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_PERL5=	yes
ALL_TARGET=	default

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_FILES=	bin/yasql etc/yasql.conf.sample

MAN1=		yasql.1

PORTDOCS=	README yasql.html

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "WITHOUT_CSV	disable support for in/out CSV files"
	@${ECHO_MSG} "WITHOUT_HIRES	disable support for high resolution benchmarking"
	@${ECHO_MSG} "WITHOUT_READKEY	disable a better input and output control"
	@${ECHO_MSG}

pre-configure:
	@${PERL} -pi -e 's|/bin/more|/usr/bin/more|' ${WRKSRC}/yasql.conf

pre-install:
	if [ -f ${PREFIX}/etc/yasql.conf ] ; then \
		${MV} ${PREFIX}/etc/yasql.conf ${PREFIX}/etc/yasql.conf.precious ; \
	fi

post-install:
	${MV} ${PREFIX}/etc/yasql.conf ${PREFIX}/etc/yasql.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@if [ -f ${PREFIX}/etc/yasql.conf.precious ] ; then \
		${MV} ${PREFIX}/etc/yasql.conf.precious ${PREFIX}/etc/yasql.conf ; \
	else \
		${ECHO_MSG} ; \
		${CAT} ${PKGMESSAGE} ; \
		${ECHO_MSG} ; \
	fi

.include <bsd.port.mk>
