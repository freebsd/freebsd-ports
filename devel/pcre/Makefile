# New ports collection makefile for:	pcre
# Date created:				08 July 1998
# Whom:					dom
#
# $FreeBSD$
#

PORTNAME=	pcre
PORTVERSION=	4.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/programming/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/unix/misc/%SUBDIR%/ \
		ftp://ftp.tin.org/pub/libs/%SUBDIR%/
MASTER_SITE_SUBDIR=	\
		${PORTNAME}

MAINTAINER=	eik@FreeBSD.org
COMMENT=	Perl Compatible Regular Expressions library

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if defined(WITH_UTF8)
CONFIGURE_ARGS+=	\
		--enable-utf8
.endif

CONFIGURE_TARGET=	\
		--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		pcregrep.1 pcretest.1
MAN3=		pcre.3 pcre_compile.3 pcre_config.3 \
		pcre_copy_named_substring.3 pcre_copy_substring.3 pcre_exec.3 \
		pcre_free_substring.3 pcre_free_substring_list.3 pcre_fullinfo.3 \
		pcre_get_named_substring.3 pcre_get_stringnumber.3 pcre_get_substring.3 \
		pcre_get_substring_list.3 pcre_info.3 pcre_maketables.3 \
		pcre_study.3 pcre_version.3 pcreapi.3 \
		pcrebuild.3 pcrecallout.3 pcrecompat.3 \
		pcrepattern.3 pcreperform.3 pcreposix.3 \
		pcresample.3

pre-configure:
	@${REINPLACE_CMD} -e '/^LIBTOOL=/s,\$$(top_builddir)/libtool,${LIBTOOL},g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STRIP} ${PREFIX}/bin/pcregrep
	@${STRIP_CMD} ${STRIP} ${PREFIX}/bin/pcretest
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/html
	@cd ${WRKSRC}; ${INSTALL_DATA} ChangeLog NEWS doc/Tech.Notes doc/*.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
