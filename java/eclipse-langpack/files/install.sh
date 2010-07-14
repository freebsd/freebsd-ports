#!/bin/sh

WRKDIR=$1; PREFIX=$2
OWNER=$3; GROUP=$4; DPERM=$5; FPERM=$6

cd ${WRKDIR}
for dir  in `find eclipse -type d | sort`; do
	install -d -o ${OWNER} -g ${GROUP} -m ${DPERM} ${PREFIX}/lib/${dir}
done

for file in `find eclipse -type f | sort`; do
	install -c -o ${OWNER} -g ${GROUP} -m ${FPERM} ${file} ${PREFIX}/lib/${file}
done
