# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	jruby
PORTVERSION=	1.7.6
CATEGORIES=	lang ruby java
MASTER_SITES=	http://jruby.org.s3.amazonaws.com/downloads/${PORTVERSION}/
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An implementation of Ruby Interpreter in Pure Java

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

WRKDIR?=	${WRKDIRPREFIX}${.CURDIR}/work
JRUBY_HOME?=	${PREFIX}/share/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
REPLACE_FILES=	${WRKSRC}/bin/jruby
REPLACE_LIST=	JAVA_HOME=${JAVA_HOME}
REPLACE_LIST_TEMP=	${REPLACE_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}
SHEBANG_FILES=	rake spec spec_translator Rakefile '*.rb'

PLIST_SUB+=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} JRUBY_HOME=${JRUBY_HOME:S,${PREFIX}/,,}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-patch:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   JRUBY_HOME:    ${JRUBY_HOME}"
	@${ECHO_MSG} "   JAVA_HOME:     ${JAVA_HOME}"

post-patch:
	@${ECHO_MSG} -n ">> Adjusting shebangs to use /usr/bin/env ..."
	@${FIND} ${WRKSRC}/bin -type f -exec ${GREP} -q '^#!/bin/bash' {} \; -exec ${REINPLACE_CMD} -e 's|^#!/bin/bash|#!/usr/bin/env bash|' {} \;
	@${FIND} ${WRKSRC} -type f -name '*.rb' -exec ${GREP} -q '^#!/usr/local/bin/ruby' {} \; -exec ${REINPLACE_CMD} -e 's|^#!/usr/local/bin/ruby|#!/usr/bin/env jruby|' {} \;
.for target in ${SHEBANG_FILES}
	@${FIND} ${WRKSRC} -type f -name ${target} -exec ${GREP} -q '^#!/usr/bin/env ruby' {} \; -exec ${REINPLACE_CMD} -e 's|^#!/usr/bin/env ruby|#!/usr/bin/env jruby|' {} \;
.endfor
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Removing unneeded files..."
	@${RM} -f `${FIND} ${WRKSRC} -name '*.bat'` `${FIND} ${WRKSRC} -name '*.orig'` `${FIND} ${WRKSRC} -name '*.exe'` `${FIND} ${WRKSRC} -name '*.bak'`
	@${ECHO_MSG} " [ DONE ]"

.for target in ${REPLACE_FILES}
	@${ECHO_MSG} -n ">> Customizing `basename ${target}`..."
	@${SED} ${REPLACE_LIST_TEMP} ${target} > ${WRKDIR}/`basename ${target}`
	@${ECHO_MSG} " [ DONE ]"
	@${MV} ${WRKDIR}/`basename ${target}` ${target}
.endfor

do-install:
	@${ECHO_MSG} -n ">> Installing JRuby files..."

	@cd ${WRKSRC}/bin \
	  && ${FIND} . -type d -exec ${MKDIR} ${JRUBY_HOME}/bin/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_SCRIPT} {} ${JRUBY_HOME}/bin/{} \;
	@cd ${WRKSRC}/lib \
	  && ${FIND} . -type d -exec ${MKDIR} ${JRUBY_HOME}/lib/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${JRUBY_HOME}/lib/{} \;

	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Installing symlinks in ${PREFIX}/bin..."
	@${LN} -sf ${JRUBY_HOME}/bin/jruby ${PREFIX}/bin/jruby
	@${LN} -sf ${JRUBY_HOME}/bin/jirb ${PREFIX}/bin/jirb
	@${ECHO_MSG} " [ DONE ]"

.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing Documents files..."
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/ \
	  && ${COPYTREE_SHARE} [A-Z]\* ${DOCSDIR})
	@(cd ${WRKSRC}/docs \
	  && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/samples \
	  && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
