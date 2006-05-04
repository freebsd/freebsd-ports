# New ports collection makefile for:	msql3
# Date created:		24 May 2004
# Whom:			Andrey Slusar <anray@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	msql
PORTVERSION=	3.7
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	anray@FreeBSD.org
COMMENT=	Version 3 of the Mini SQL relational database system

CONFLICTS=	msql-2*

INSTALLS_SHLIB=	YES
USE_PERL5=	YES

LATEST_LINK=	msql3

# Not free for commercial use.
RESTRICTED=	"restrictive copyright (no commercial use)"

MAKE_ENV+=	WRKSRC=${WRKSRC}

MSQLDATA=	directory.mm dll_os2.mm install.mm lex.mm libinstall.mm \
		library_os2.mm library_unix.mm makegen makegen.cf object.mm \
		program.mm touch.mm yacc.mm

DOCS=		README RELEASE_NOTES BUGS doc/License doc/Manual \
		doc/Perl doc/acl.txt

post-patch:
		cd ${FILESDIR}; \
		${REINPLACE_CMD} -e "s|'bison -y' byacc|byacc 'bison -y'|g" \
			${WRKSRC}/conf/configure

do-configure:
		cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./setup
		@${SETENV} ${MAKE_ENV} ${PERL} ${SCRIPTDIR}/customize_scripts

pre-install:
		@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	    ${INSTALL_SCRIPT} ${WRKSRC}/scripts/run_daemon ${PREFIX}/bin
.for f in msqladmin msqlimport msqlexport
	    ${CHGRP} msql ${PREFIX}/bin/${f}
.endfor
	    ${CHGRP} msql ${PREFIX}/sbin/msql3d
	    ${CHMOD} 751 ${PREFIX}/etc/msql3/
	    ${CHOWN} -R msql:msql ${PREFIX}/etc/msql3/
	    ${MKDIR} ${PREFIX}/etc/rc.d
		@if [ ! -f ${PREFIX}/etc/rc.d/msql3.sh ]; then \
			${ECHO_MSG} "Installing ${PREFIX}/etc/rc.d/msql3.sh startup file."; \
			${INSTALL_SCRIPT} -m 751 ${FILESDIR}/msql3.sh \
				${PREFIX}/etc/rc.d/msql3.sh; \
		fi
	    ${MKDIR} ${DATADIR}/makegen
.for i in ${MSQLDATA}
	    ${INSTALL_SCRIPT} ${WRKSRC}/src/makegen/${i} ${DATADIR}/makegen
.endfor
	    ${INSTALL_SCRIPT} ${WRKSRC}/src/site.mm ${DATADIR}/makegen
.if !defined(NOPORTDOCS)
	    ${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	    ${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE="- You must manually obtain ${DISTFILES} from 'http://www.Hughes.com.au/download/' and place it in ${DISTDIR}.  The distribution requires registration prior to use"
.endif

.include <bsd.port.post.mk>
