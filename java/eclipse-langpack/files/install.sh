#!/bin/sh

wrksrc=$1; prefix=$2
owner=$3; group=$4; dperm=$5; fperm=$6
plist=$7

for subr in ${PLIST_SUB}; do
	plist_sub="${plist_sub} `echo $subr|sed 's/^\([^=][^=]*\)=\(.*\)$/-e s|%%\1%%|\2|g/'`"
done

sed $plist_sub ${plist} > ${wrksrc}/plist.tmp

for dir in `sed -n "s|^@dirrm ||p" ${wrksrc}/plist.tmp | sort`; do
	install -d -o ${owner} -g ${group} -m ${dperm} ${prefix}/$dir
done

for file in `sed "/^@dirrm /d; s|^eclipse/||" ${wrksrc}/plist.tmp`; do
	install -c -o ${owner} -g ${group} -m ${fperm} ${wrksrc}/${file} ${prefix}/eclipse/${file}
done
